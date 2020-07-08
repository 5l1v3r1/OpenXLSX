//
// Created by Kenneth Balslev on 28/06/2020.
//

#ifndef OPENXLSX_XLXMLFILE_IMPL_HPP
#define OPENXLSX_XLXMLFILE_IMPL_HPP

// ===== Standard Library Includes
#include <iostream>
#include <memory>
#include <string>
#include <map>

// ===== OpenXLSX Includes
#include "XLXmlData_Impl.hpp"

namespace OpenXLSX::Impl
{

    class XLDocument;

    template <typename T>
    class XLXmlFile
    {
    public:

        explicit XLXmlFile() = default;

        /**
         * @brief Constructor. Creates an object using the parent XLDocument object, the relative file path
         * and a data object as input.
         * @param parent
         * @param filePath The path of the XML file, relative to the root.
         * @param xmlData An std::string object with the XML data to be represented by the object.
         */
        explicit XLXmlFile(XLDocument& parentDoc, const XLXmlData& xmlData)
                : m_xmlData(xmlData),
                  m_xlParentDoc(&parentDoc) {
            //ParseXMLData();
        }

        /**
         * @brief Copy constructor. Default (shallow) implementation used.
         */
        XLXmlFile(const XLXmlFile& other) = default;

        XLXmlFile(XLXmlFile&& other) noexcept = default;

        /**
         * @brief Destructor. Default implementation used.
         */
        virtual ~XLXmlFile() = default;

        /**
         * @brief The assignment operator. The default implementation has been used.
         * @return A reference to the new object.
         */
        XLXmlFile& operator=(const XLXmlFile&) = default;

        XLXmlFile& operator=(XLXmlFile&& other) noexcept = default;

        /**
         * @brief
         * @return
         */
        bool isEmpty() const {
            return m_xmlData.isEmpty();
        }

        /**
         * @brief Provide the XML data represented by the object.
         * @param xmlData A std::string with the XML data.
         */
        void SetXmlData(const XLXmlData& xmlData) {
            m_xmlData = xmlData;
            ParseXMLData();
        }

        /**
         * @brief Method for getting the XML data represented by the object.
         * @return A std::string with the XML data.
         */
        XLXmlData GetXmlData() const {
            return m_xmlData;
        }

    protected:

        /**
         * @brief This method returns the underlying XMLDocument object.
         * @return A pointer to the XMLDocument object.
         * @note This method is final, i.e. it cannot be overridden.
         */
        XMLDocument& XmlDocument() {
            return m_xmlData.getXmlDocument();
        }

        /**
         * @brief This method returns the underlying XMLDocument object.
         * @return A pointer to the const XMLDocument object.
         * @note This method is final, i.e. it cannot be overridden.
         */
        const XMLDocument& XmlDocument() const {
            return m_xmlData.getXmlDocument();
        }

        XLDocument& ParentDoc() {
            return *m_xlParentDoc;
        }

        /**
         * @brief The parseXMLData method is used to map or copy the XML data to the internal data structures.
         * @return true on success; otherwise false.
         * @note This is a pure virtual function, meaning that this must be implemented in derived classes.
         */
        void ParseXMLData() {
            static_cast<T&>(*this).ParseXMLData();
        }


    private:

        XLXmlData   m_xmlData = XLXmlData(); /**< */
        XLDocument* m_xlParentDoc; /**< */

    };

}  // namespace OpenXLSX::Impl

#endif //OPENXLSX_XLXMLFILE_IMPL_HPP
