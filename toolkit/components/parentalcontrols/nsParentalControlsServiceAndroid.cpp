/* -*- Mode: C++; tab-width: 2; indent-tabs-mode:nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsParentalControlsService.h"
#include "AndroidBridge.h"
#include "nsString.h"
#include "nsIFile.h"

NS_IMPL_ISUPPORTS(nsParentalControlsService, nsIParentalControlsService)

nsParentalControlsService::nsParentalControlsService() :
  mEnabled(false)
{
  if (mozilla::AndroidBridge::HasEnv()) {
    mEnabled = mozilla::widget::android::GeckoAppShell::IsUserRestricted();
  }
}

nsParentalControlsService::~nsParentalControlsService()
{
}

NS_IMETHODIMP
nsParentalControlsService::GetParentalControlsEnabled(bool *aResult)
{
  *aResult = mEnabled;
  return NS_OK;
}

NS_IMETHODIMP
nsParentalControlsService::GetBlockFileDownloadsEnabled(bool *aResult)
{
  return NS_ERROR_NOT_AVAILABLE;
}

NS_IMETHODIMP
nsParentalControlsService::GetLoggingEnabled(bool *aResult)
{
  return NS_ERROR_NOT_AVAILABLE;
}

NS_IMETHODIMP
nsParentalControlsService::Log(int16_t aEntryType,
                               bool aBlocked,
                               nsIURI *aSource,
                               nsIFile *aTarget)
{
  return NS_ERROR_NOT_AVAILABLE;
}

NS_IMETHODIMP
nsParentalControlsService::RequestURIOverride(nsIURI *aTarget,
                                              nsIInterfaceRequestor *aWindowContext,
                                              bool *_retval)
{
  return NS_ERROR_NOT_AVAILABLE;
}

NS_IMETHODIMP
nsParentalControlsService::RequestURIOverrides(nsIArray *aTargets,
                                               nsIInterfaceRequestor *aWindowContext,
                                               bool *_retval)
{
  return NS_ERROR_NOT_AVAILABLE;
}