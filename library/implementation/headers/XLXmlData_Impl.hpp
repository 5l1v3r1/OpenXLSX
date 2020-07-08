//
// Created by Kenneth Balslev on 27/06/2020.
//

#ifndef OPENXLSX_XLXMLDATA_IMPL_HPP
#define OPENXLSX_XLXMLDATA_IMPL_HPP

#include <string>
#include <utility>
#include <sstream>
#include <memory>
#include "XLXml_Impl.hpp"

namespace OpenXLSX::Impl
{

    /**
     * @brief
     */
    class XLXmlData
    {
    public:

        explicit XLXmlData(const std::string& filePath = "",
                           const std::string& xmlData = "" ) : m_filePath(filePath),
                                                               m_xmlData(std::make_shared<XMLDocument>()) {
            setXmlData(xmlData);
        }

        ~XLXmlData() = default;

        XLXmlData(const XLXmlData& other) = default;

        XLXmlData(XLXmlData&& other) = default;

        XLXmlData& operator=(const XLXmlData& other) = default;

        XLXmlData& operator=(XLXmlData&& other) = default;

        /**
         * @brief Provide the XML data represented by the object.
         * @param xmlData A std::string with the XML data.
         */
        void setXmlData(const std::string& xmlData) {
            m_xmlData->load_string(xmlData.c_str(), pugi::parse_default | pugi::parse_ws_pcdata);
        }

        /**
         * @brief Method for getting the XML data represented by the object.
         * @return A std::string with the XML data.
         */
        std::string getXmlData() const {
            std::ostringstream stream;
            m_xmlData->save(stream, "", pugi::format_raw);
            return stream.str();
        }

        /**
         * @brief
         * @return
         */
        bool isEmpty() const {
            return !m_xmlData->document_element();
        }

        /**
         * @brief
         * @param filePath
         */
        void setFilePath(const std::string& filePath) {
            m_filePath = filePath;
        }

        /**
         * @brief
         * @return
         */
        const std::string& getFilePath() const {
            return m_filePath;
        }

        /**
         * @brief This method returns the underlying XMLDocument object.
         * @return A pointer to the XMLDocument object.
         * @note This method is final, i.e. it cannot be overridden.
         */
        XMLDocument& getXmlDocument() {
            return *m_xmlData;
        }

        /**
         * @brief This method returns the underlying XMLDocument object.
         * @return A pointer to the const XMLDocument object.
         * @note This method is final, i.e. it cannot be overridden.
         */
        const XMLDocument& getXmlDocument() const {
            return *m_xmlData;
        }

    private:

        std::string                  m_filePath = "";
        std::shared_ptr<XMLDocument> m_xmlData  = std::make_shared<XMLDocument>();
    };

}  // namespace OpenXLSX::Impl

#endif //OPENXLSX_XLXMLDATA_IMPL_HPP
